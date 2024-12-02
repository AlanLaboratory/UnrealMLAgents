#include "IActionReceiver.h"

FActionBuffers FActionBuffers::Empty = FActionBuffers(FActionSegment<float>::Empty, FActionSegment<int32>::Empty);
