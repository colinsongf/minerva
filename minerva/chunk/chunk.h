#pragma once

#include "common/scale.h"
#include "common/nvector.h"
#include "dag/physical_dag.h"

namespace minerva {

class Chunk {
  friend class ChunkElewise;

 public:
  static Chunk Constant(const Scale& size, float val);
  static Chunk Randn(const Scale& size, float mu, float var);
  Chunk();
  Chunk(PhysicalDataNode* node);
  Chunk(const Chunk& other);
  PhysicalDataNode* data_node() const { return data_node_; }
  Chunk& operator=(const Chunk& other);

  // TODO Elewise, to be implemented
  friend Chunk operator + (Chunk , Chunk );
  friend Chunk operator - (Chunk , Chunk );
  friend Chunk operator / (Chunk , Chunk );
  friend Chunk operator + (Chunk , float );
  friend Chunk operator - (Chunk , float );
  friend Chunk operator * (Chunk , float );
  friend Chunk operator / (Chunk , float );
  friend Chunk operator + (float , Chunk );
  friend Chunk operator - (float , Chunk );
  friend Chunk operator * (float , Chunk );
  friend Chunk operator / (float , Chunk );
  void operator += (Chunk );
  void operator -= (Chunk );
  void operator *= (Chunk );
  void operator /= (Chunk );
  void operator += (float );
  void operator -= (float );
  void operator *= (float );
  void operator /= (float );
  void operator - ();

  friend Chunk operator*(Chunk, Chunk); // Matrix multiplication
  Scale Size() const;
  int Size(int) const;
  // TODO Functionality to split and merge
  Chunk Trans();
  static std::vector<Chunk> Compute(std::vector<Chunk> params,
      std::vector<Scale> result_sizes, PhysicalComputeFn* fn);
  static Chunk Generate(const Scale& result_size, PhysicalDataGenFn* fn);

 private:
  PhysicalDataNode* data_node_; // Set up in constructor
};

class ChunkElewise {
 public:
  static Chunk Exp(Chunk);
  static Chunk Ln(Chunk);
  static Chunk Sigmoid(Chunk);
};

} // end of namespace minerva

