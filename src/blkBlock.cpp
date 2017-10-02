#include <blkBlock.hpp>
#include <iomanip>

char blk::Block::fill = '.';

int blk::Block::minLine(void) const {
  return - ref_height;
}

int blk::Block::maxLine(void) const {
  return height - ref_height;
}

blk::Block::Block(int w, int h, int ref_w, int ref_h) 
  : width(w), height(h), ref_width(ref_w), ref_height(ref_h) {}

void blk::Block::printLine(std::ostream& os, int i) const {
  if((i >= minLine()) && (i < maxLine()))
    printInBoundsLine(os,i);
  else
    os << std::string(width,fill);
}

blk::Block::~Block() {}

std::ostream& blk::operator<<(std::ostream& os,
			      const blk::Expr& e) {
  if(e != nullptr) {
    int max = e->maxLine();
    for(int i = e->minLine(); i < max; ++i) {
      os << std::setw(4) << i << " :   ";
      e->printLine(os,i);
      os << std::endl;
    }
  }
  else
    os << "null";
  return os;
}
