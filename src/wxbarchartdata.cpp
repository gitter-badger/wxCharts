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

/// @file

#include "wxbarchartdata.h"

wxBarChartDataset::wxBarChartDataset(const wxColor &fillColor,
									 const wxColor &strokeColor,
									 const wxVector<wxDouble> &data)
	: m_fillColor(fillColor), m_strokeColor(strokeColor), m_data(data)
{
}

const wxColor& wxBarChartDataset::GetFillColor() const
{
	return m_fillColor;
}

const wxColor& wxBarChartDataset::GetStrokeColor() const
{
	return m_strokeColor;
}

const wxVector<wxDouble>& wxBarChartDataset::GetData() const
{
	return m_data;
}

wxBarChartData::wxBarChartData(const wxVector<wxString> &labels)
	: m_labels(labels)
{
}

void wxBarChartData::AddDataset(wxBarChartDataset::ptr dataset)
{
	m_datasets.push_back(dataset);
}

const wxVector<wxString>& wxBarChartData::GetLabels() const
{
	return m_labels;
}

const wxVector<wxBarChartDataset::ptr>& wxBarChartData::GetDatasets() const
{
	return m_datasets;
}
