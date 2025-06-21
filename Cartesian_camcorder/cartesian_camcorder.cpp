#include "cartesian_camcorder.h"
#include <iostream>
#include <algorithm>

CartesianCamcorder::CartesianCamcorder() 
    : planning_apparatus(std::make_unique<PlanningApparatus>()) {}

std::shared_ptr<SmartRecording> CartesianCamcorder::record(const CognitiveEvent& event) {
    if (!isSalient(event)) {
        return nullptr; // Event not important enough to record
    }

    // Process the event to create a 'smart' representation
    std::map<std::string, std::any> processed_content = processEventForRecording(event);
    auto smart_recording = std::make_shared<SmartRecording>(event, processed_content);

    recorded_events.push_back(smart_recording);
    return smart_recording;
}

CognitiveEvent CartesianCamcorder::playback(const SmartRecording& smart_recording) {
    // Create a new CognitiveEvent representing the "awareness" or "observation" of the playback
    std::map<std::string, std::any> awareness_content;
    awareness_content["focus_on"] = smart_recording.getProcessedContent();
    awareness_content["observer_state"] = std::string("aware_of_playback");
    
    // Handle recursive level - store the processed content to avoid dangling references
    auto processed_content = smart_recording.getProcessedContent();
    int current_level = 0;
    auto level_it = processed_content.find("recursive_level");
    if (level_it != processed_content.end() && 
        level_it->second.type() == typeid(int)) {
        current_level = std::any_cast<int>(level_it->second);
    }
    awareness_content["recursive_level"] = current_level + 1;

    CognitiveEvent awareness_event("awareness_of_playback", awareness_content, 
                                  smart_recording.getRecordingTimestamp() + 0.01);

    // The planning apparatus (or other cognitive systems) engages during playback
    planning_apparatus->processPlaybackAwareness(awareness_event);

    return awareness_event; // This new event can then be fed back into 'record'
}

bool CartesianCamcorder::isSalient(const CognitiveEvent& /* event */) const {
    // In a real model, this would be a complex attentional filter.
    // For simplicity in this example, we record all events.
    return true;
}

std::map<std::string, std::any> CartesianCamcorder::processEventForRecording(const CognitiveEvent& event) const {
    std::map<std::string, std::any> processed;
    
    if (event.getEventType() == "perception") {
        // Process perception events
        if (event.getContent().type() == typeid(std::string)) {
            std::string content = std::any_cast<std::string>(event.getContent());
            processed["object_identified"] = content;
            processed["agent"] = std::string("you"); // The system represents that 'you' are perceiving
            processed["action"] = std::string("seeing");
            processed["context"] = std::string("current_environment");
            processed["recursive_level"] = 0; // Base level for perception events
            
            // Determine relations based on content
            if (content.find("flower") != std::string::npos) {
                processed["relations"] = std::string("desirable_object");
            } else {
                processed["relations"] = std::string("neutral");
            }
        }
    } else if (event.getEventType() == "awareness_of_playback") {
        // This is the key for recursive consciousness: recording the act of being conscious
        if (event.getContent().type() == typeid(std::map<std::string, std::any>)) {
            // Store the content map to avoid dangling references
            auto content_map = std::any_cast<const std::map<std::string, std::any>&>(event.getContent());
            
            auto focus_it = content_map.find("focus_on");
            if (focus_it != content_map.end()) {
                processed["awareness_of"] = focus_it->second;
            }
            
            auto level_it = content_map.find("recursive_level");
            if (level_it != content_map.end()) {
                processed["awareness_level"] = level_it->second;
                processed["recursive_level"] = level_it->second; // Copy the level
            }
            
            processed["note"] = std::string("This contributes to the feeling of an enduring self and consciousness of consciousness");
        }
    } else {
        // Basic processing for other event types
        processed["raw_content"] = event.getContent();
        processed["processed_status"] = std::string("basic");
        processed["recursive_level"] = 0;
    }
    
    return processed;
}

void CartesianCamcorder::printRecordedEvents() const {
    std::cout << "\n=== Recorded Events (" << recorded_events.size() << " total) ===" << std::endl;
    for (size_t i = 0; i < recorded_events.size(); ++i) {
        std::cout << i + 1 << ". " << *recorded_events[i] << std::endl;
        
        // Show recursive level if available - store content to avoid dangling references
        auto processed_content = recorded_events[i]->getProcessedContent();
        auto level_it = processed_content.find("recursive_level");
        if (level_it != processed_content.end() && 
            level_it->second.type() == typeid(int)) {
            int level = std::any_cast<int>(level_it->second);
            if (level > 0) {
                std::cout << "   Recursive Level: " << level << std::endl;
            }
        }
    }
    std::cout << "=====================================" << std::endl;
} 