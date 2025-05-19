class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int la = ay2 - ay1;
        int wa = ax2 - ax1;
        int lb = by2 - by1 ;
        int wb = bx2 - bx1; 
        int aa  = la * wa;
        int ab  = lb * wb;
        int overlapl= max( 0 , min(ay2 , by2) - max(ay1 , by1));
        int overlapw = max( 0 , min(ax2 , bx2) - max(ax1 , bx1));
        int overlapa = overlapl * overlapw;
        int totalarea = aa + ab - overlapa ;
        return totalarea; 
    }
};