class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int length1 = ( ay2 - ay1 ) ;
        int width1 = ( ax2 - ax1 ) ;
        int length2 = ( by2 - by1 ) ;
        int width2 = ( bx2 - bx1 ) ;
        int area1 = length1 * width1 ;
        int area2 = length2 * width2 ;
        int overlaplength = max ( 0 , min ( ay2 , by2 ) - max ( ay1 , by1 )) ;
        int overlapwidth = max ( 0 , min(ax2 , bx2 ) - max ( ax1 , bx1  )) ;
        int overlaparea = overlaplength * overlapwidth ;
        int totalarea = area1 + area2 - overlaparea ; 
        return totalarea ;
        
    }
};