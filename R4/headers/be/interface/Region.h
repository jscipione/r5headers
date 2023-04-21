/*******************************************************************************
/
/	File:			Region.h
/
/   Description:    BRegion represents an area that's composed of individual
/                   rectangles.
/
/	Copyright 1992-98, Be Incorporated, All Rights Reserved
/
*******************************************************************************/

#ifndef	_REGION_H
#define	_REGION_H

#include <BeBuild.h>
#include <InterfaceDefs.h>
#include <Rect.h>

/*----------------------------------------------------------------*/
/*----- BRegion class --------------------------------------------*/

class BRegion {

public:
				BRegion();
				BRegion(const BRegion &region);
virtual			~BRegion();	

		BRegion	&operator=(const BRegion &from);

		BRect	Frame() const;	
		BRect	RectAt(int32 index);
		int32	CountRects();
		void	Set(BRect newBounds);
		bool	Intersects(BRect r) const;
		bool	Contains(BPoint pt) const;
		void	PrintToStream() const;
		void	OffsetBy(int32 dh, int32 dv);
		void	MakeEmpty();
		void	Include(BRect r);
		void	Include(const BRegion*);
		void	Exclude(BRect r);
		void	Exclude(const BRegion*);
		void	IntersectWith(const BRegion*);

/*----- Private or reserved -----------------------------------------*/

private:

friend class BView;
friend class BDirectWindow;
friend void copy_region_n(BRegion*, BRegion*, long);
friend void and_region_complex(BRegion*, BRegion*, BRegion*);
friend void and_region_1_to_n(BRegion*, BRegion*, BRegion*);
friend void and_region(BRegion*, BRegion*, BRegion*);
friend void append_region(BRegion*, BRegion*, BRegion*);
friend void r_or(long, long, BRegion*, BRegion*, BRegion*, long*, long *);
friend void or_region_complex(BRegion*, BRegion*, BRegion*);
friend void or_region_1_to_n(BRegion*, BRegion*, BRegion*);
friend void or_region_no_x(BRegion*, BRegion*, BRegion*);
friend void or_region(BRegion*, BRegion*, BRegion*);
friend void sub(long, long, BRegion*, BRegion*, BRegion*, long*, long*);
friend void sub_region_complex(BRegion*, BRegion*, BRegion*);
friend void r_sub(long , long, BRegion*, BRegion*, BRegion*, long*, long*);
friend void sub_region(BRegion*, BRegion*, BRegion*);

		void	__AddRect(BRect r);
		void	set_size(long new_size);
		long	find_small_bottom(long y1, long y2, long *hint, long *where);

private:
		long	f_count;
		long	f_data_size;
		BRect	f_bound;
		BRect	*f_data;
};

/*-------------------------------------------------------------*/
/*-------------------------------------------------------------*/

#endif /* _REGION_H */
