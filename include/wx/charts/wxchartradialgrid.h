/*
	Copyright (c) 2016 Xavier Leclercq

	Permission is hereby granted, free of charge, to any person obtaining a
	copy of this software and associated documentation files (the "Software"),
	to deal in the Software without restriction, including without limitation
	the rights to use, copy, modify, merge, publish, distribute, sublicense,
	and/or sell copies of the Software, and to permit persons to whom the
	Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
	THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
	IN THE SOFTWARE.
*/

/*
	Part of this file were copied from the Chart.js project (http://chartjs.org/)
	and translated into C++.

	The files of the Chart.js project have the following copyright and license.

	Copyright (c) 2013-2016 Nick Downie
	Released under the MIT license
	https://github.com/nnnick/Chart.js/blob/master/LICENSE.md
*/

#ifndef _WX_CHARTS_WXCHARTRADIALGRID_H_
#define _WX_CHARTS_WXCHARTRADIALGRID_H_

#include "wxchartelement.h"
#include "wxchartradialgridoptions.h"
#include <wx/graphics.h>

// This class represents the radial grid displayed in the
// background of some of the chart controls like for instance 
// the polar area chart.
class wxChartRadialGrid : public wxChartElement
{
public:
	wxChartRadialGrid(const wxSize &size, wxDouble minValue,
		wxDouble maxValue, const wxChartRadialGridOptions& options);

	virtual bool HitTest(const wxPoint &point) const;

	void Draw(wxGraphicsContext &gc);

	void Resize(const wxSize &size);

private:
	void DrawCircular(wxGraphicsContext &gc);
	void DrawPolygonal(wxGraphicsContext &gc);
	static wxPoint2DDouble CalculateCenter(const wxSize& size);
	static wxDouble CalculateCenterOffset(wxDouble value, 
		wxDouble drawingArea, wxDouble minValue,
		wxDouble maxValue);
	void BuildYLabels(size_t steps);

private:
	wxChartRadialGridOptions m_options;
	wxSize m_size;
	wxDouble m_drawingArea;
	wxPoint2DDouble m_center;
	wxVector<wxString> m_yLabels;
	size_t m_steps;
};

#endif
