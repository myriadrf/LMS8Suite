/**
@file 	gui_utilities.h
@author Lime Microsystems (www.limemicro.com)
@brief 	Common functions used by all panels
*/
#include <map>
#include "LMS8001_parameters.h"
#include <vector>
class wxPanel;
class wxWindow;
class LMS8001;

namespace LMS8001_WXGUI
{

void UpdateControlsByMap(wxPanel* panel, LMS8001* lmsControl, const std::map<wxWindow*, LMS8Parameter> &wndId2param);

typedef std::pair<int, int> indexValuePair;
typedef std::vector < indexValuePair > indexValueMap;

int index2value(int index, const indexValueMap &pairs);
int value2index(int value, const indexValueMap &pairs);

void UpdateTooltips(const std::map<wxWindow*, LMS8Parameter> &wndId2param, bool replace);

}
