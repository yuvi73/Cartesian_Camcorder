#ifndef CARTESIAN_CAMCORDER_H
#define CARTESIAN_CAMCORDER_H

#include "cognitive_event.h"
#include "smart_recording.h"
#include "planning_apparatus.h"
#include <vector>
#include <memory>
#include <map>
#include <any>

/**
 * An internal memory system responsible for recording and playing back
 * selected mental events. Its operations constitute consciousness.
 */
class CartesianCamcorder {
private:
    std::vector<std::shared_ptr<SmartRecording>> recorded_events;
    std::unique_ptr<PlanningApparatus> planning_apparatus;
    
    /**
     * Determines if an event is important enough to be recorded.
     * This is where unconscious processing might occur if attention is elsewhere.
     */
    bool isSalient(const CognitiveEvent& event) const;
    
    /**
     * Transforms a raw CognitiveEvent into its 'smart' representation,
     * adding context, relationships, and "self-awareness" components.
     */
    std::map<std::string, std::any> processEventForRecording(const CognitiveEvent& event) const;

public:
    CartesianCamcorder();
    
    /**
     * Records a CognitiveEvent if it is deemed salient, transforming it into a SmartRecording.
     * This "smart capture" retroactively bestows consciousness upon the event.
     */
    std::shared_ptr<SmartRecording> record(const CognitiveEvent& event);
    
    /**
     * Plays back a SmartRecording, making it "watched" by other parts of the cognitive system.
     * Crucially, this act of 'watching' the playback is itself a new cognitive event
     * that can be recorded and played back, enabling recursive awareness.
     */
    CognitiveEvent playback(const SmartRecording& smart_recording);
    
    // Utility methods
    size_t getRecordedEventCount() const { return recorded_events.size(); }
    const std::vector<std::shared_ptr<SmartRecording>>& getRecordedEvents() const { return recorded_events; }
    void printRecordedEvents() const;
};

#endif // CARTESIAN_CAMCORDER_H 