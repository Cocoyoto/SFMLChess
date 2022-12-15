#pragma once

#include <unordered_map>

template <typename Id, typename Resource>
class ResourceHolder
{
public :
	ResourceHolder();
	~ResourceHolder();

	const Resource* getResource(const Id& id) const noexcept;
	void setResource(const Id& id, const Resource& resource);

private:
	std::unordered_map <Id, Resource> m_resourcesMap;
};