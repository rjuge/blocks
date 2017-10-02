#pragma once

#include <iostream>
#include <memory>

namespace blk {
  class Block;

  // Expression are shared pointers on blocks.
  // This is a c++11 flavoured typedef.
  using Expr = std::shared_ptr<const Block>;

  std::ostream& operator<<(std::ostream& os, const blk::Expr& e);

  class Block {
  public:
    
    Block()                              = delete;
    Block(const Block& cpy)              = delete;
    Block& operator=(const Block& cpy)   = delete;
    Block(Block&& cpy)                   = delete;
    Block& operator=(Block&& cpy)        = delete;

  private:

    int width;
    int height;
    int ref_width;
    int ref_height; 

    // Min in-block line number
    int minLine(void) const;

    // 1+max in-block line number
    int maxLine(void) const;

    friend std::ostream& operator<<(std::ostream& os, const blk::Expr& e);

  protected:

    // This is the only available constuctor... for derivated classes only. 
    Block(int w, int h, int ref_w, int ref_h);

    // The line number have to be a line inside the block.
    virtual void printInBoundsLine(std::ostream& os, int i) const = 0;

    // Prints a line of the block (0 is the line of the reference
    // point).
    void printLine(std::ostream& os, int i) const;
    
  public:

    // This defines the space filling caracter.
    static char fill;

    virtual ~Block();

    int getWidth()     const {return width;     }
    int getHeight()    const {return height;    }
    int getRefWidth()  const {return ref_width; }
    int getRefHeight() const {return ref_height;}

  };
}
