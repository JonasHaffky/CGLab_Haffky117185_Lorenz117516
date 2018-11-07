#include "geonode.hpp"

GeoNode::GeoNode(Node* t_parent, std::string const& t_name,
		glm::mat4 const& t_local, glm::mat4 const& t_world,
		model const& t_model) :
	Node{t_parent, t_name, t_local, t_world},
	m_geometry{t_model}
{}

GeoNode::GeoNode(std::string const& t_name,
		glm::mat4 const& t_local, glm::mat4 const& t_world,
		model const& t_model) :
	Node{t_name},
	m_geometry{t_model}
{
	setLocalTransform(t_local);
	setWorldTransform(t_world);
}

model GeoNode::getGeo(){
	return m_geometry;
}

void GeoNode::setGeo(model t_geometry){
 	m_geometry = t_geometry;
}

void GeoNode::setDistance(float t_distance) {
	m_distanceFromOrigin = t_distance;
}

float GeoNode::getDistance() const {
	return m_distanceFromOrigin;
}

void GeoNode::setSpeed(float t_speed) {
	m_speed = t_speed;
}

float GeoNode::getSpeed() const {
	return m_speed;
}