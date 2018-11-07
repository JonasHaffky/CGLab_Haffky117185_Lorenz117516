#include "camnode.hpp"

CamNode::CamNode(Node* t_parent, std::string const& t_name, 
			glm::mat4 const& t_local, glm::mat4 const& t_world, 
			bool const& t_isPerspective, bool const& t_isEnabled,
			glm::mat4 t_projectionMatrix) :
	Node{t_parent, t_name, t_local, t_world},
	m_isPerspective{t_isPerspective},
	m_isEnabled{t_isEnabled},
	m_projectionMatrix{t_projectionMatrix}
{}

CamNode::CamNode(std::string const& t_name, 
			glm::mat4 const& t_local, glm::mat4 const& t_world, 
			bool const& t_isPerspective, bool const& t_isEnabled,
			glm::mat4 t_projectionMatrix) :
	Node{t_name},
	m_isPerspective{t_isPerspective},
	m_isEnabled{t_isEnabled},
	m_projectionMatrix{t_projectionMatrix}
{
	setLocalTransform(t_local);
	setWorldTransform(t_world);
}

bool CamNode::getPerspective() const{
	return m_isPerspective;
}

bool CamNode::getEnabled() const{
	return m_isEnabled;
}

void CamNode::setEnabled(bool t_enabled){
	m_isEnabled = t_enabled;
}

glm::mat4 CamNode::getProjectionMatrix() const{
	return m_projectionMatrix;
}

void CamNode::setProjectionMatrix(glm::mat4 t_matrix){
	m_projectionMatrix = t_matrix;
}