#include "planning_apparatus.h"
#include <any>
#include <map>

void PlanningApparatus::processPlaybackAwareness(const CognitiveEvent& awareness_event) {
    if (awareness_event.getEventType() == "awareness_of_playback") {
        // Extract content from the awareness event
        const auto& content = awareness_event.getContent();
        
        if (content.type() == typeid(std::map<std::string, std::any>)) {
            const auto& content_map = std::any_cast<const std::map<std::string, std::any>&>(content);
            
            // Get recursive level
            int recursive_level = 0;
            auto level_it = content_map.find("recursive_level");
            if (level_it != content_map.end() && level_it->second.type() == typeid(int)) {
                recursive_level = std::any_cast<int>(level_it->second);
            }
            
            // Get focus_on content
            auto focus_it = content_map.find("focus_on");
            if (focus_it != content_map.end() && focus_it->second.type() == typeid(std::map<std::string, std::any>)) {
                const auto& focus_content = std::any_cast<const std::map<std::string, std::any>&>(focus_it->second);
                
                if (recursive_level == 1) {
                    // First level awareness
                    auto obj_it = focus_content.find("object_identified");
                    if (obj_it != focus_content.end() && obj_it->second.type() == typeid(std::string)) {
                        std::cout << "Planning Apparatus notes: 'I am now conscious of " 
                                  << std::any_cast<std::string>(obj_it->second) << "'" << std::endl;
                    }
                } else if (recursive_level > 1) {
                    // Higher level awareness (recursive consciousness)
                    auto awareness_it = focus_content.find("awareness_of");
                    if (awareness_it != focus_content.end() && awareness_it->second.type() == typeid(std::map<std::string, std::any>)) {
                        const auto& nested_content = std::any_cast<const std::map<std::string, std::any>&>(awareness_it->second);
                        auto nested_obj_it = nested_content.find("object_identified");
                        
                        std::string object_name = "something";
                        if (nested_obj_it != nested_content.end() && nested_obj_it->second.type() == typeid(std::string)) {
                            object_name = std::any_cast<std::string>(nested_obj_it->second);
                        }
                        
                        std::cout << "Planning Apparatus notes: 'I am conscious of my awareness of " 
                                  << object_name << "' (level " << recursive_level << ")" << std::endl;
                    }
                }
            }
        }
    }
} 