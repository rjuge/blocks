#include <blkOver.hpp>
#include <string>

blk::Expr blk::over(blk::Expr blkA, blk::Expr blkB) { 
  return blk::Expr(new Over (blkA, blkB));
}

blk::Over::Over(blk::Expr blkA, blk::Expr blkB) 
  : Block(compute_width(blkA, blkB),
	  compute_height(blkA, blkB),
	  compute_ref_width(blkA, blkB),
	  compute_ref_height(blkA, blkB)), top(blkA), bottom(blkB){}

void blk::Over::printInBoundsLine(std::ostream& os, int i) const {
  if(i < top->getHeight() - top->getRefHeight()) {
    std::string before = std::string(std::max(bottom->getRefWidth() - top->getRefWidth(), 0), blk::Block::fill);
    std::string after  = std::string(std::max((bottom->getWidth() - bottom->getRefWidth()) - (top->getWidth() - top->getRefWidth()), 0), blk::Block::fill);
    os << before;
    _printLine(top, os, i);
    os << after;
  }    
  else{
    std::string before = std::string(std::max(top->getRefWidth() - bottom->getRefWidth(), 0), blk::Block::fill);
    std::string after  = std::string(std::max((top->getWidth() - top->getRefWidth()) - (bottom->getWidth() - bottom->getRefWidth()), 0), blk::Block::fill);
    os << before;
    _printLine(bottom, os, i - (top->getHeight() - top->getRefHeight()) - bottom->getRefHeight());
    os << after;
  }
}

int blk::Over::compute_width(blk::Expr blkA, blk::Expr blkB){
  return compute_ref_width(blkA, blkB)
	 + std::max(blkA->getWidth() - blkA->getRefWidth(), 
		    blkB->getWidth() - blkB->getRefWidth());
}

int blk::Over::compute_height(blk::Expr blkA, blk::Expr blkB){
  return blkA->getHeight() + blkB->getHeight();
}

int blk::Over::compute_ref_width(blk::Expr blkA, blk::Expr blkB){
  return std::max(blkA->getRefWidth(), blkB->getRefWidth());
}

int blk::Over::compute_ref_height(blk::Expr blkA, blk::Expr blkB){
  return blkA->getRefHeight();
}

