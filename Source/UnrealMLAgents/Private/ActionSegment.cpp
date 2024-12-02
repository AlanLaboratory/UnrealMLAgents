#include "ActionSegment.h"

// Static member initialization
template <typename T>
FActionSegment<T> FActionSegment<T>::Empty = FActionSegment<T>(FActionSegment<T>::GetEmptyArray(), 0, 0);
