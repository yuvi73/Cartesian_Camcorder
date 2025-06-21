#ifndef SMART_RECORDING_H
#define SMART_RECORDING_H

#include "cognitive_event.h"
#include <map>
#include <string>
#include <iostream>

/**
 * Represents a 'smart' capture of a CognitiveEvent, processed into a higher-level,
 * abstracted representation, including interrelatedness, usable by cognitive systems.
 * This is what the Cartesian Camcorder records and plays back, constituting consciousness.
 */
class SmartRecording {
private:
    CognitiveEvent original_event;
    std::map<std::string, std::any> processed_content;
    double recording_timestamp;

public:
    SmartRecording(const CognitiveEvent& event, const std::map<std::string, std::any>& content);
    
    // Getters
    CognitiveEvent getOriginalEvent() const { return original_event; }
    std::map<std::string, std::any> getProcessedContent() const { return processed_content; }
    double getRecordingTimestamp() const { return recording_timestamp; }
    
    // Utility
    std::string toString() const;
    std::any getProcessedValue(const std::string& key) const;
    friend std::ostream& operator<<(std::ostream& os, const SmartRecording& recording);
};

#endif // SMART_RECORDING_H 