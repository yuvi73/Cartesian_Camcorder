#include "cognitive_event.h"
#include <sstream>

CognitiveEvent::CognitiveEvent(const std::string& type, const std::any& cont, double time)
    : event_type(type), content(cont), timestamp(time) {}

std::string CognitiveEvent::toString() const {
    std::ostringstream oss;
    oss << "<" << event_type << " at " << timestamp << ": ";
    
    // Handle different content types
    if (content.type() == typeid(std::string)) {
        oss << std::any_cast<std::string>(content);
    } else if (content.type() == typeid(int)) {
        oss << std::any_cast<int>(content);
    } else if (content.type() == typeid(double)) {
        oss << std::any_cast<double>(content);
    } else {
        oss << "[complex content]";
    }
    
    oss << ">";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const CognitiveEvent& event) {
    os << event.toString();
    return os;
} 