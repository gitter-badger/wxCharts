/*
    Copyright (c) 2016-2017 Xavier Leclercq

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

#ifndef _WX_CHARTS_WXCHARTOPTIONS_H_
#define _WX_CHARTS_WXCHARTOPTIONS_H_

#include "wxchartpadding.h"
#include "wxchartmultitooltipoptions.h"

/// Options for the wxChartCtrl control.
class wxChartOptions
{
public:
    /// Constructs a wxChartOptions
    /// instance.
    wxChartOptions();

    /// Gets the padding options.
    /// @return The padding options.
    const wxChartPadding& GetPadding() const;
    void SetPadding(const wxChartPadding &padding);

    /// Whether the chart automatically resizes 
    /// when the control size changes.
    /// @retval true Resize the chart when control
    /// size changes.
    /// @retval false Don't automatically resize
    /// the chart when the control size changes.
    bool IsResponsive() const;

    /// Whether to display tooltips.
    /// @retval true Display tooltips.
    /// @retval false Don't display tooltips.
    bool ShowTooltips() const;
    /// Enables or disable tooltips.
    /// @param show True to enable tooltips, false to disable them.
    void SetShowTooltips(bool show);
    /// Gets the options for the multi-tooltips (const version).
    /// @return The options for the multi-tooltips.
    const wxChartMultiTooltipOptions& GetMultiTooltipOptions() const;
    /// Gets the options for the multi-tooltips (non-const version).
    /// @return The options for the multi-tooltips.
    wxChartMultiTooltipOptions& GetMultiTooltipOptions();

    /// Whether a contextual menu that allows the user
    /// to save the graph to file should be provided.
    /// @retval true A contextual menu with a Save As item is provided.
    /// @retval false No contextual menu is provided.
    bool IsSaveAsMenuEnabled() const;

private:
    wxChartPadding m_padding;
    bool m_responsive;
    bool m_showTooltips;
    wxChartMultiTooltipOptions m_multiTooltipOptions;
    bool m_enableSaveAsMenu;
};

#endif
