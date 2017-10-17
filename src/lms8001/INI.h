/*
   Feather INI Parser - 1.28
   You are free to use this for whatever you wish.

   If you find a bug, please debug the cause and look into a solution.
   Post your compiler, version and the cause or fix in the issues section.

   Written by Turbine.

   Website:
   http://code.google.com/p/feather-ini-parser/downloads

   Help:
   http://code.google.com/p/feather-ini-parser/wiki/Tutorials
*/

#pragma once

#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include <stdint.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define FINI_SAFE

#if __cplusplus >= 201103L
  #include <unordered_map>
  #define CPP11
  #define ALLOCATE_SECTIONS 100
  #define ALLOCATE_KEYS 5
#else
  #include <map>
#endif

///
template<class T, class U>
   static T Convert(U value)
{
   std::stringstream sout;
   T result;

   sout << value;
   sout >> result;

   return result;
}

///
template<class T = std::string, class U = std::string, class V = std::string>
   class INI
{
public:
   typedef char char_t;
   typedef T section_t;
   typedef U key_t;
   typedef V value_t;

   ///Type definitions
#ifdef CPP11
   typedef typename std::unordered_map<key_t, value_t> keys_t;
   typedef typename std::unordered_map<section_t, keys_t*> sections_t;
#else
   typedef typename std::map<key_t, value_t> keys_t;
   typedef typename std::map<section_t, keys_t*> sections_t;
#endif

   typedef typename keys_t::iterator keysit_t;
   typedef typename sections_t::iterator sectionsit_t;

   typedef typename std::pair<key_t, value_t> keyspair_t;
   typedef typename std::pair<section_t, keys_t*> sectionspair_t;

   ///Settings & Tweaks
   static const int BUFFER_SIZE = 32;

   ///Data members
   keys_t* current;
   sections_t sections;

   ///Constuctor/Destructor
   INI(std::string filename, bool parseFile = true);
   ~INI();

   ///Accessing structure
   keys_t& operator[](section_t section);

   bool create(const section_t section);
   bool select(const section_t section);

   //Set
   bool set(const key_t key, const value_t value);
   template<class W, class X>
      bool set(const W key, const X value)
         { return set(Convert<key_t>(key), Convert<value_t>(value)); }

   //Get
   value_t get(const key_t key, value_t def = value_t());  //Get value, if none exists
   std::string get(const key_t key, const char_t* def = "");  //Can handle const char* without casting
   template<class X, class W>
      X get(const W key, X def = X())
         { return Convert<X>(get(Convert<value_t>(key), Convert<value_t>(def))); }

   ///Functions
   void nake(const char_t*);  //Strip the line of any non-interpretable characters
   bool parse();
   bool parseBinary();
   void clear();

   ///Output
   void save(std::string filename = "");
   void saveBinary(std::string filename = "");

private:
   std::string filename;

   ///Output
   std::string makeSection(const section_t& section);
   std::string makeKeyValue(const key_t& key, const value_t& value);
};

///
template<class T, class U, class V>
   INI<T, U, V>::INI(std::string filename, bool parseFile): filename(filename), current(NULL)
{
   if (parseFile)
      parse();

#ifdef CPP11
   sections.reserve(ALLOCATE_SECTIONS);
#endif
}

///
template<class T, class U, class V>
   INI<T, U, V>::~INI()
{
   clear();
}

///
template<class T, class U, class V>
   typename INI<T, U, V>::keys_t& INI<T, U, V>::operator[](section_t section)
{
#ifdef FINI_SAFE
  if (!sections[section])
    sections[section] = new keys_t;
#endif

   return *sections[section];
}

///
template<class T, class U, class V>
   void INI<T, U, V>::clear()
{
   for(sectionsit_t i = sections.begin(); i != sections.end(); i++)
      delete i->second;

   current = NULL;
}

///
template<class T, class U, class V>
   bool INI<T, U, V>::create(const section_t section)
{
   if (select(section))
      return false;

   current = new keys_t;
   sections[section] = current;

#ifdef CPP11
   current->reserve(ALLOCATE_KEYS);
#endif

   return true;
}

///
template<class T, class U, class V>
   bool INI<T, U, V>::select(const section_t section)
{
   sectionsit_t sectionsit = sections.find(section);
   if (sectionsit == sections.end())
      return false;

   current = sectionsit->second;

   return true;
}

///
template<class T, class U, class V>
   bool INI<T, U, V>::set(const key_t key, const value_t value)
{
   if (current == NULL)
      return false;

   (*current)[key] = value;

   return true;
}

///
template<class T, class U, class V>
   typename INI<T, U, V>::value_t INI<T, U, V>::get(const key_t key, const value_t def)
{
   keysit_t keys = current->find(key);
   if (current == NULL || keys == current->end())
      return def;

   return keys->second;
}

///
template<class T, class U, class V>
   std::string INI<T, U, V>::get(const key_t key, const char_t* def)
{
   return get(key, (std::string)def);
}

///
template<class T, class U, class V>
   void INI<T, U, V>::nake(const char_t*)
{

}

///
template<class T, class U, class V>
   bool INI<T, U, V>::parse()
{
   current = NULL;
   std::ifstream file(filename.c_str());
   if (!file.is_open())
      return false;

   char_t line[BUFFER_SIZE];
   bool first = true;

   while(!file.eof())
   {
      file.getline(line, BUFFER_SIZE);

      if (first)
      {
         first = false;
         if (line[0] == (char)0xEF)
            memmove(line, line + 3, BUFFER_SIZE - 3);
      }

      nake(line);

      if (line[0])
      {
         if (!((strlen(line) >= 2) && line[0] == '/' && line[1] == '/'))  //Ignore comment
         {
            if (line[0] == '[')  //Section
            {
               std::stringstream out;
               section_t section;

               size_t length = strlen(line) - 2;  //Without section brackets
               while(isspace(line[length + 1]))  //Leave out any additional new line characters
                  --length;

               char_t* ssection = (char_t*)calloc(sizeof(char_t), length + 1);

               strncpy(ssection, line + 1, length);  //Count after first bracket

               current = new keys_t;

               out << ssection;
               out >> section;

               sections[section] = current;
            }
            else  //Key
            {
               std::stringstream out1, out2;
               key_t key;
               value_t value;

               char_t* skey;
               char_t* svalue;

               skey = strtok(line, "=");
               svalue = strtok(NULL, "=");

               out1 << skey;
               out1 >> key;

               out2 << svalue;
               out2 >> value;

               if (value != "")
                  (*current)[key] = value;
            }
         }
      }
   }

   file.close();

   return true;
}

///GOES HERE PARSE

///
template<class T, class U, class V>
   std::string INI<T, U, V>::makeSection(const section_t& section)
{
   std::stringstream line;
   line << '[' << section << ']' << std::endl;

   return line.str();
}

///
template<class T, class U, class V>
   std::string INI<T, U, V>::makeKeyValue(const key_t& key, const value_t& value)
{
   std::stringstream line;
   line << key << '=' << value << std::endl;

   return line.str();
}

///
template<class T, class U, class V>
   void INI<T, U, V>::save(std::string filename)
{
   std::ofstream file(((filename == "")? this->filename: filename).c_str(), std::ofstream::trunc);

   //Loop through sections
   for(INI::sectionsit_t i = sections.begin(); i != sections.end(); i++)
   {
      if (i->second->size() == 0)  //No keys/values in section, skip to next
         continue;

      //Write section
      const std::string temp = makeSection(i->first);
      const char_t* line = temp.c_str();
      file.write(line, strlen(line));

      for(INI::keysit_t j = i->second->begin(); j != i->second->end(); j++)
      {
         //Write key and value
         const std::string temp = makeKeyValue(j->first, j->second);
         const char_t* line = temp.c_str();
         file.write(line, strlen(line));
      }
   }

   file.close();
}

///
template<class T, class U, class V>
   bool INI<T, U, V>::parseBinary()
{
   current = NULL;
   std::ifstream file(filename.c_str(), std::ifstream::binary);
   if (!file.is_open())
      return false;

   sections.clear();

   uint16_t sectionCount;
   uint8_t keyCount;
   key_t key;
   value_t value;
   section_t section;
   uint8_t ss;

   file.read((char*)&sectionCount, sizeof(sectionCount));

   for(uint32_t i = 0; i < sectionCount; i++)
   {
      if (i > 0)
         file.seekg(file.tellg() + 1);

      file.read((char*)&keyCount, sizeof(keyCount));
      file >> section;

      create(section);

      for(uint8_t j = 0; j < keyCount; j++)
      {
         file >> key;
         file >> value;
         set(key, value);
      }
   }

   file.close();

   return true;
}

///
template<class T, class U, class V>
   void INI<T, U, V>::saveBinary(std::string filename)
{
   std::ofstream file(((filename == "")? this->filename: filename).c_str(), std::ofstream::trunc | std::ofstream::binary);
   uint16_t sectionCount = sections.size();
   uint8_t keyCount;

   file.write((char*)&sectionCount, sizeof(sectionCount));

   //Loop through sections
   for(INI::sectionsit_t i = sections.begin(); i != sections.end(); i++)
   {
      keyCount = i->second->size();
      file.write((char*)&keyCount, sizeof(keyCount));

      file << i->first << endl;

      for(INI::keysit_t j = i->second->begin(); j != i->second->end(); j++)
      {
         file << j->first << endl;
         file << j->second << endl;
      }
   }

   file.close();
}
