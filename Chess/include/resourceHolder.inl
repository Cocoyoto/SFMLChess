#include <stdexcept>

template <typename Id, typename Resource>
ResourceHolder<Id, Resource>::ResourceHolder():
	m_resourcesMap()
{

}

template <typename Id, typename Resource>
ResourceHolder<Id, Resource>::~ResourceHolder()
{

}

template<typename Id, typename Resource>
const Resource* ResourceHolder<Id, Resource>::getResource(const Id& id) const noexcept
{
	try
	{
		return &m_resourcesMap.at(id);
	}
	catch (std::out_of_range& error)
	{
		return nullptr;
	}
}

template<typename Id, typename Resource>
void ResourceHolder<Id, Resource>::setResource(const Id& id, const Resource& resource)
{
	m_resourcesMap.insert({ id, std::move(resource) });
}