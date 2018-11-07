#ifndef GEO_NODE_HPP
#define GEO_NODE_HPP

#include <glbinding/gl/types.h>
#include "node.hpp"
#include "model.hpp"

// use gl definitions from glbinding 
using namespace gl;

class GeoNode : public Node{
	public:
		GeoNode(Node* t_parent, std::string const& t_name,
			glm::mat4 const& t_local, glm::mat4 const& t_world,
			model const& t_model);
		GeoNode(std::string const& t_name,
			glm::mat4 const& t_local, glm::mat4 const& t_world,
			model const& t_model);
		model getGeo();
		void setGeo(model t_geometry);
        void setDistance(float t_distance);
		float getDistance() const;
		void setSpeed(float t_speed);
        float getSpeed() const;

	private:
		model m_geometry;
        float m_distanceFromOrigin;
        float m_speed;

};

#endif