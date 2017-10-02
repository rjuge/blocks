#pragma once

#include <blkBlock.hpp>


namespace blk {

  // This factory creates an expression... which is a debug block.
  Expr over(char symb, int width, int height, int ref_width, int ref_height);

  class Over : public Block {
  private:
    
    char s;

    friend Expr over(char symb,
		      int width, int height,
		      int ref_width, int ref_height);

    Over(char symb,
	  int width, int height,
	  int ref_width, int ref_height);

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
