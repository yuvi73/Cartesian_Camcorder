#ifndef PLANNING_APPARATUS_H
#define PLANNING_APPARATUS_H

#include "cognitive_event.h"
#include <iostream>

/**
 * Represents the part of the cognitive system that uses the SmartRecordings
 * for prediction, planning, learning, and voluntary actions, including speech.
 */
class PlanningApparatus {
public:
    PlanningApparatus() = default;
    
    /**
     * This method signifies how the planning apparatus accesses and utilizes
     * the conscious experiences (i.e., the SmartRecordings and their playbacks).
     */
    void processPlaybackAwareness(const CognitiveEvent& awareness_event);
    
    /**
     * Additional methods for cognitive processing could be added here:
     * - predict()
     * - plan()
     * - learn()
     * - generateVerbalReport()
     */
};

#endif // PLANNING_APPARATUS_H 