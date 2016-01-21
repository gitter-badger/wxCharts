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

#include "wxchartradialgrid.h"
#include "wxchartutilities.h"

wxChartRadialGrid::wxChartRadialGrid(const wxSize &size, 
									 wxDouble minValue,
									 wxDouble maxValue,
									 const wxChartRadialGridOptions& options)
	: m_options(options), m_size(size), m_center(CalculateCenter(size))
{
	m_drawingArea = (size.x < size.y) ? size.x / 2 : size.y / 2;
	wxDouble graphMinValue;
	wxDouble graphMaxValue;
	wxDouble valueRange = 0;
	wxDouble stepValue;
	wxChartUtilities::CalculateGridRange(minValue, maxValue, 
		graphMinValue, graphMaxValue, valueRange, m_steps, stepValue);
	BuildYLabels(m_steps);
}

bool wxChartRadialGrid::HitTest(const wxPoint &point) const
{
	return false;
}

void wxChartRadialGrid::Draw(wxGraphicsContext &gc)
{
	switch (m_options.GetStyle())
	{
	case wxCHARTRADIALGRIDSTYLE_CIRCULAR:
		DrawCircular(gc);
		break;

	case wxCHARTRADIALGRIDSTYLE_POLYGONAL:
		DrawPolygonal(gc);
		break;
	}
}

void wxChartRadialGrid::DrawCircular(wxGraphicsContext &gc)
{
	// Don't draw a centre value so start from 1
	for (size_t i = 1; i < m_yLabels.size(); ++i)
	{
		wxDouble yCenterOffset = i * (m_drawingArea / m_steps);
		wxDouble yHeight = m_center.m_y - yCenterOffset;

		wxGraphicsPath path = gc.CreatePath();
		path.AddArc(m_center.m_x, m_center.m_y, yCenterOffset, 0, 2 * M_PI, true);
		path.CloseSubpath();

		wxPen pen(m_options.GetLineColor(), m_options.GetLineWidth());
		gc.SetPen(pen);
		gc.StrokePath(path);

		if (m_options.ShowLabels())
		{
			wxFont font(wxSize(0, m_options.GetFontSize()),
				m_options.GetFontFamily(), m_options.GetFontStyle(), wxFONTWEIGHT_NORMAL);
			gc.SetFont(font, m_options.GetFontColor());
			gc.DrawText(m_yLabels[i], m_center.m_x, yHeight);
		}
	}
}

void wxChartRadialGrid::DrawPolygonal(wxGraphicsContext &gc)
{
	// Don't draw a centre value so start from 1
	for (size_t i = 1; i < m_yLabels.size(); ++i)
	{
		wxGraphicsPath path = gc.CreatePath();
		path.MoveToPoint(100, 100);
		for (size_t j = 1; j < 4; ++j)
		{
			path.AddLineToPoint(50, 50);
			//wxPoint2DDouble pointPosition = 
			//CalculateCenterOffset();

		}
		path.CloseSubpath();

		wxPen pen(m_options.GetLineColor(), m_options.GetLineWidth());
		gc.SetPen(pen);
		gc.StrokePath(path);
	}
}

void wxChartRadialGrid::Resize(const wxSize &size)
{
	m_size = size;
	m_drawingArea = (size.x < size.y) ? size.x / 2 : size.y / 2;
	m_center = CalculateCenter(size);
}

wxPoint2DDouble wxChartRadialGrid::CalculateCenter(const wxSize& size)
{
	return wxPoint2DDouble(size.GetWidth() / 2, size.GetHeight() / 2);
}

wxDouble wxChartRadialGrid::CalculateCenterOffset(wxDouble value, 
												  wxDouble drawingArea,
												  wxDouble minValue,
												  wxDouble maxValue)
{
	wxDouble scalingFactor = drawingArea / (maxValue - minValue);

	return ((value - minValue) * scalingFactor);
}

void wxChartRadialGrid::BuildYLabels(size_t steps)
{
	m_yLabels.clear();

	for (size_t i = 0; i <= steps; ++i)
	{
		m_yLabels.push_back("10");
	}
}
