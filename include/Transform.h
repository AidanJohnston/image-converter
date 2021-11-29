#ifndef __TRANSFORM_H_
#define __TRANSFORM_H_
#include <utility>

const std::pair<const int, const int> zzOrderToMatIndices(const int zzindex);
const int matIndicesToZZOrder(const int row, const int column);

#endif