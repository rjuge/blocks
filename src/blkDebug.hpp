#pragma once

#include <blkBlock.hpp>


namespace blk {

  // This factory creates an expression... which is a debug block.
  Expr debug(char symb, int width, int height, int ref_width, int ref_height);

  class Debug : public Block {
  private:
    
    char s;

    friend Expr debug(char symb,
		      int width, int height,
		      int ref_width, int ref_height);

    Debug(char symb,
	  int width, int height,
	  int ref_width, int ref_height);

  public:

    Debug()                            = delete;
    Debug(const Debug& cpy)            = delete;
    Debug(Debug&& cpy)                 = delete;
    Debug& operator=(const Debug& cpy) = delete;
    Debug& operator=(Debug&& cpy)      = delete;
    virtual ~Debug() {}

  protected:

    virtual void printInBoundsLine(std::ostream& os, int i) const override;
  };
  
}
