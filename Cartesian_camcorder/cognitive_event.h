#ifndef COGNITIVE_EVENT_H
#define COGNITIVE_EVENT_H

#include <string>
#include <any>
#include <iostream>

/**
 * Represents a fundamental mental occurrence that is initially unconscious.
 * Each CognitiveEvent is initially devoid of consciousness; consciousness 
 * is bestowed upon it by the camcorder's process.
 */
class CognitiveEvent {
private:
    std::string event_type;  // E.g., "perception", "thought", "emotion", "decision"
    std::any content;        // The raw data or content of the event
    double timestamp;        // When the event occurred

public:
    CognitiveEvent(const std::string& type, const std::any& cont, double time);
    
    // Getters
    std::string getEventType() const { return event_type; }
    std::any getContent() const { return content; }
    double getTimestamp() const { return timestamp; }
    
    // Utility
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const CognitiveEvent& event);
};

#endif // COGNITIVE_EVENT_H 