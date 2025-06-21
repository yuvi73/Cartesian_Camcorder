#include "smart_recording.h"
#include <sstream>

SmartRecording::SmartRecording(const CognitiveEvent& event, const std::map<std::string, std::any>& content)
    : original_event(event), processed_content(content), recording_timestamp(event.getTimestamp()) {}

std::string SmartRecording::toString() const {
    std::ostringstream oss;
    oss << "<SmartRecording of " << original_event.getEventType() << ": ";
    
    // Try to get object_identified from processed content
    auto it = processed_content.find("object_identified");
    if (it != processed_content.end()) {
        if (it->second.type() == typeid(std::string)) {
            oss << std::any_cast<std::string>(it->second);
        } else {
            oss << "[object]";
        }
    } else {
        // Fallback to original content
        if (original_event.getContent().type() == typeid(std::string)) {
            oss << std::any_cast<std::string>(original_event.getContent());
        } else {
            oss << "[content]";
        }
    }
    
    oss << ">";
    return oss.str();
}

std::any SmartRecording::getProcessedValue(const std::string& key) const {
    auto it = processed_content.find(key);
    if (it != processed_content.end()) {
        return it->second;
    }
    return std::any(); // Return empty any if key not found
}

std::ostream& operator<<(std::ostream& os, const SmartRecording& recording) {
    os << recording.toString();
    return os;
} 