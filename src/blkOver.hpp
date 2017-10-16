#pragma once

#include <blkBlock.hpp>

namespace blk {

  // This factory creates an expression... which is a debug block.
  Expr over(Expr blkA, Expr blkB);

  class Over : public Block {
  private:

    Expr top;
    Expr bottom;

    friend Expr over(Expr blkA, Expr blkB);

    Over(Expr blkA, Expr blkB);

    static int compute_width(Expr blkA, Expr blkB);
    static int compute_height(Expr blkA, Expr blkB);
    static int compute_ref_width(Expr blkA, Expr blkB);
    static int compute_ref_height(Expr blkA, Expr blkB);

  public:

    Over()                            = delete;
    Over(const Over& cpy)            = delete;
    Over(Over&& cpy)                 = delete;
    Over& operator=(const Over& cpy) = delete;
    Over& operator=(Over&& cpy)      = delete;
    virtual ~Over() {}

  protected:
    virtual void printInBoundsLine(std::ostream& os, int i) const override;
  };
  
}
