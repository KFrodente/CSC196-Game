#include "Memory.h"
#include <iostream>

using namespace std;

yogi::MemoryTracker yogi::g_memoryTracker;

void* operator new (size_t size) {
	void* p = malloc(size);

	yogi::g_memoryTracker.Add(p, size);

	return p;
}

void operator delete (void* memAddress, size_t size) {
	yogi::g_memoryTracker.Remove(memAddress, size);
	free(memAddress);
}

namespace yogi {

	void MemoryTracker::Add(void* address, size_t size)
	{
		m_bytesAllocated += size;
		m_numAllocations++;
	}
	
	void MemoryTracker::Remove(void* address, size_t size)
	{
		m_bytesAllocated -= size;
		m_numAllocations--;
	}
	
	void MemoryTracker::DisplayInfo()
	{
		cout << "current bytes allocated: " << m_bytesAllocated << endl;
		cout << "current number of allocations: " << m_numAllocations << endl;
	}

}