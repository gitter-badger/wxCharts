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

#ifndef _WX_CHARTS_WXLINECHARTCTRL_H_
#define _WX_CHARTS_WXLINECHARTCTRL_H_

#include "wxchart.h"
#include "wxlinechartoptions.h"
#include "wxchartgrid.h"
#include "wxchartpoint.h"
#include <wx/control.h>
#include <wx/sharedptr.h>

class wxLineChartDataset
{
public:
	typedef wxSharedPtr<wxLineChartDataset> ptr;

	wxLineChartDataset(const wxColor &dotColor,
		const wxColor &dotStrokeColor, const wxVector<wxDouble> &data);

	const wxColor& GetDotColor() const;
	const wxColor& GetDotStrokeColor() const;
	const wxVector<wxDouble>& data() const;

private:
	wxColor m_dotColor;
	wxColor m_dotStrokeColor;
	wxVector<wxDouble> m_data;
};

class wxLineChartData
{
public:
	wxLineChartData(const wxVector<wxString> &labels);

	void AddDataset(wxLineChartDataset::ptr dataset);

	const wxVector<wxString>& GetLabels() const;
	const wxVector<wxLineChartDataset::ptr>& GetDatasets() const;

	wxDouble GetMinValue() const;
	wxDouble GetMaxValue() const;

private:
	wxVector<wxString> m_labels;
	wxVector<wxLineChartDataset::ptr> m_datasets;
};

class wxLineChartCtrl : public wxChart
{
public:
	wxLineChartCtrl(wxWindow *parent, wxWindowID id, const wxLineChartData& data,
		const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize, 
		long style = 0);

	wxDouble GetMinValue() const;
	wxDouble GetMaxValue() const;

private:
	void OnPaint(wxPaintEvent &evt);
	void OnSize(wxSizeEvent& evt);

private:
	struct PointClass : public wxChartPoint
	{
		typedef wxSharedPtr<PointClass> ptr;

		PointClass(wxDouble x, wxDouble y, wxDouble radius,
			unsigned int strokeWidth, const wxColor &strokeColor,
			const wxColor &fillColor);
	};

private:
	wxLineChartOptions m_options;
	wxChartGrid m_grid;
	wxVector<PointClass::ptr> m_points;
	wxDouble m_minValue;
	wxDouble m_maxValue;

	DECLARE_EVENT_TABLE();
};

#endif
