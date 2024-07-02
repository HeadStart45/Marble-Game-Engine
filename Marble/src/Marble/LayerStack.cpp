#include "mbpch.h"
#include "LayerStack.h"

Marble::LayerStack::LayerStack()
{
	m_LayerInsert = m_Layers.begin();
}

Marble::LayerStack::~LayerStack()
{
	for (Layer* layer : m_Layers)
		delete layer;
}

void Marble::LayerStack::PushLayer(Layer* layer)
{
	m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
}

void Marble::LayerStack::PushOverlay(Layer* overlay)
{
	m_Layers.emplace_back(overlay);
}

void Marble::LayerStack::PopLayer(Layer* layer)
{
	auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);

	if (it != m_Layers.end())
	{
		m_Layers.erase(it);
		m_LayerInsert--;
	}
}

void Marble::LayerStack::PopOverlay(Layer* overlay)
{
	auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);

	if (it != m_Layers.end())
		m_Layers.erase(it);
	
}
