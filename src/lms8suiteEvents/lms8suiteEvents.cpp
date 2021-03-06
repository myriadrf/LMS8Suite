#include "lms8suiteEvents.h"

wxDEFINE_EVENT(CONTROL_PORT_CONNECTED, wxCommandEvent);
wxDEFINE_EVENT(CONTROL_PORT_DISCONNECTED, wxCommandEvent);
wxDEFINE_EVENT(LMS7_CONTROL_PORT_CONNECTED, wxCommandEvent);
wxDEFINE_EVENT(LMS7_CONTROL_PORT_DISCONNECTED, wxCommandEvent);
wxDEFINE_EVENT(DATA_PORT_CONNECTED, wxCommandEvent);
wxDEFINE_EVENT(DATA_PORT_DISCONNECTED, wxCommandEvent);
wxDEFINE_EVENT(CGEN_FREQUENCY_CHANGED, wxCommandEvent);
wxDEFINE_EVENT(LOG_MESSAGE, wxCommandEvent);
wxDEFINE_EVENT(LMS8_TXBAND_CHANGED, wxCommandEvent);
wxDEFINE_EVENT(LMS8_RXPATH_CHANGED, wxCommandEvent);
