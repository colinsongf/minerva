#pragma once

#include <vector>

#include "common/scale.h"
#include "context.h"
#include "op.h"

namespace minerva {

struct PhysicalData;
struct PhysicalOp;
class PhysicalDataGenFn;
class PhysicalComputeFn;

struct PhysicalData {
  Scale size, offset, chunk_index;
  //DataNodeContext context; // TODO how to set context ?
  uint64_t data_id;
  PhysicalDataGenFn* data_gen_fn;
};

struct PhysicalOp {
  //OpNodeContext context; // TODO how to set context ?
  //OpExecutor* executor; // TODO [jermaine] I think we don't need to set the function pointer here, because there might be several types of implementation for a single function which needs to be determined later.
  PhysicalComputeFn* compute_fn;
};

class PhysicalDataGenFn : public BasicFn {
};

class PhysicalComputeFn : public BasicFn {
 public:
  //virtual void Execute(std::vector<PhysicalData> inputs,
      //std::vector<PhysicalData> outputs, PhysicalOp& op) = 0;
};

} // end of namespace minerva