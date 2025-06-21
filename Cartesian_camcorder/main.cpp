#include "cartesian_camcorder.h"
#include <iostream>
#include <chrono>
#include <thread>

/**
 * Demonstration of the Cartesian Camcorder model of consciousness.
 * This shows how recursive awareness can be achieved through the
 * mechanical process of recording and playback.
 */
int main() {
    std::cout << "=== Cartesian Camcorder Model Demonstration ===" << std::endl;
    std::cout << "This demonstrates how consciousness emerges from\n";
    std::cout << "the mechanical process of smart recording and playback.\n\n";
    
    CartesianCamcorder camcorder;
    
    // Step 1: Create initial perception events
    std::cout << "Step 1: Creating initial perception events..." << std::endl;
    
    CognitiveEvent flower_perception("perception", std::string("red flower"), 1.0);
    CognitiveEvent tree_perception("perception", std::string("tall tree"), 1.1);
    
    std::cout << "Created: " << flower_perception << std::endl;
    std::cout << "Created: " << tree_perception << std::endl;
    
    // Step 2: Record these events (this bestows consciousness upon them)
    std::cout << "\nStep 2: Recording events (bestowing consciousness)..." << std::endl;
    
    auto flower_recording = camcorder.record(flower_perception);
    auto tree_recording = camcorder.record(tree_perception);
    
    if (flower_recording) {
        std::cout << "Recorded: " << *flower_recording << std::endl;
    }
    if (tree_recording) {
        std::cout << "Recorded: " << *tree_recording << std::endl;
    }
    
    // Step 3: Playback recordings (this creates awareness)
    std::cout << "\nStep 3: Playing back recordings (creating awareness)..." << std::endl;
    
    CognitiveEvent flower_awareness = camcorder.playback(*flower_recording);
    std::cout << "Created awareness event: " << flower_awareness << std::endl;
    
    // Step 4: Record the awareness (recursive consciousness)
    std::cout << "\nStep 4: Recording awareness (recursive consciousness)..." << std::endl;
    
    auto awareness_recording = camcorder.record(flower_awareness);
    if (awareness_recording) {
        std::cout << "Recorded awareness: " << *awareness_recording << std::endl;
    }
    
    // Step 5: Playback the awareness recording (higher-level consciousness)
    std::cout << "\nStep 5: Playing back awareness (higher-level consciousness)..." << std::endl;
    
    CognitiveEvent meta_awareness = camcorder.playback(*awareness_recording);
    std::cout << "Created meta-awareness event: " << meta_awareness << std::endl;
    
    // Step 6: Record the meta-awareness (even higher-level consciousness)
    std::cout << "\nStep 6: Recording meta-awareness..." << std::endl;
    
    auto meta_awareness_recording = camcorder.record(meta_awareness);
    if (meta_awareness_recording) {
        std::cout << "Recorded meta-awareness: " << *meta_awareness_recording << std::endl;
    }
    
    // Step 7: Playback the meta-awareness (demonstrating infinite regress solution)
    std::cout << "\nStep 7: Playing back meta-awareness..." << std::endl;
    
    CognitiveEvent meta_meta_awareness = camcorder.playback(*meta_awareness_recording);
    std::cout << "Created meta-meta-awareness event: " << meta_meta_awareness << std::endl;
    
    // Step 8: Show all recorded events
    std::cout << "\nStep 8: Summary of all recorded events:" << std::endl;
    camcorder.printRecordedEvents();
    
    // Step 9: Demonstrate the solution to infinite regress
    std::cout << "\nStep 9: Demonstrating the solution to infinite regress..." << std::endl;
    std::cout << "The Cartesian Camcorder model addresses infinite regress by:\n";
    std::cout << "1. Using a single mechanical system (the camcorder) for all levels\n";
    std::cout << "2. Creating a 'parade of self versions' where each observes predecessors\n";
    std::cout << "3. Avoiding the need for separate observers at each level\n";
    std::cout << "4. Implementing recursive awareness through the same physical process\n\n";
    
    std::cout << "Total events recorded: " << camcorder.getRecordedEventCount() << std::endl;
    std::cout << "This demonstrates how consciousness can emerge from purely\n";
    std::cout << "mechanical processes without requiring infinite observers.\n";
    
    return 0;
} 