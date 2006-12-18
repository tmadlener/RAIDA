// MUSS NOCH modifiziert werden !!!
// -*- C++ -*-
#ifndef AIDA_IPLOTTERREGION_H
#define AIDA_IPLOTTERREGION_H 1

#include <string>
#include <vector>

namespace AIDA {

class IBaseHistogram;
class IDataPointSet;
class IFunction;
class IInfo;
class IPlotterLayout;
class IPlotterStyle;

/**
 * User level interface to a plotter region.
 * A region is managed by a plotter.
 * A region must be seen as a scene manager handling
 * a custome "plotting" scene. In general this kind of scene
 * may be in 2D or 3D. In 2D, the scene have "coarse graining parts" 
 * like two axis, data representations within the axis. It may have 
 * various other parts like a grid, a title, an info area. In 3D, 
 * the scene have in general three axis,
 * a different global layout, some data representations within the
 * axis area and also scene parts like title, grid, etc...
 * 
 *  To customize all these, some "style" interfaces had been introduced.
 * In general there is one style interface per "scene part" ; then
 * IAxisStyle, IDataStyle, ITitleStyle, IInfoStyle. Oftenly
 * a "scene part" contains text, line, fill area, etc.... For example
 * an "axis" have a line, ticks, text for tick labels, text for 
 * the label of the axis, the magnitude, etc... A "coarse graining scene part"
 * style contains various accessor to "atomic" styles like IMarkerStyle, 
 * ILineStyle, IFillStyle that permits to build a "customization block"
 * to modify a scene part.
 * 
 *  A global style "block", the IPlotterStyle, could be retreived
 * from a plotting region. This global style block have accessors
 * to the various "coarse graining scene parts" of the plotting scene.
 * Through it, we hope to offer a lot of customization in a convenient 
 * way...
 *
 *  The keywords "scene" and "part" had been borrowed from the
 * OpenInventor terminology.
 *
 * @author T. Kraemer, DESY
 * @version $Id: IPlotterRegionROOT.h,v 1.1 2006-12-18 09:49:56 tkraemer Exp $
 */

class IPlotterRegion {

public: 
    /// Destructor.
    virtual ~IPlotterRegion() { /* nop */; }

  /**
   * Add a data analysis object (histogram, function, cloud,...)
   * in the list of things to plot in the region.
   * Activate the underlying graphic toolkit in order to bring
   * something in the screen window(s) attached to the plotter.
   * It assumes that the plotter had been mapped on the
   * screen with its show method.
   */
    virtual bool plot(const IBaseHistogram & histogram, const std::string & options = "") = 0;

    virtual bool plot(const IBaseHistogram & histogram, const IPlotterStyle & style, const std::string & options = "") = 0;

    virtual bool plot(const IFunction & function, const std::string & options = "") = 0;

    virtual bool plot(const IFunction & function, const IPlotterStyle & style, const std::string & options = "") = 0;

    virtual bool plot(const IDataPointSet & dataPointSet, const std::string & options = "") = 0;

    virtual bool plot(const IDataPointSet & dataPointSet, const IPlotterStyle & style, const std::string & options = "") = 0;

  /**
   *  Remove a data analysis object in the list of things to plot in the region.
   *  Activate the graphic layer to update the screen window.
   */
    virtual bool remove(const IBaseHistogram & histogram) = 0;

    virtual bool remove(const IFunction & function) = 0;

    virtual bool remove(const IDataPointSet & dataPointSet) = 0;

  /**
   * Clear the list of things to plot in the region.
   * Clear the corresponding area on screen window(s).
   */
    virtual void clear() = 0;

  /**
   * Set various plotting paramters for the region.
   * Activate the graphic layer and update the screen window(s)
   * if needed.
   */
    virtual bool setParameter(const std::string & parameter, const std::string & options = "") = 0;

  /**
   * Get value of a parameter. 
   * @param paramName Name of the parameter.
   * @return the value.
   */
    virtual std::string parameterValue(const std::string & parameter) const = 0;

    virtual std::vector<std::string>  availableParameterOptions(const std::string & parameter) const = 0;

    virtual std::vector<std::string>  availableParameters() const = 0;

  /**
   * Get the style of the region.
   */
    virtual IPlotterStyle & style() = 0;

  /**
   * Set the style of a region.
   */
    virtual bool setStyle(const IPlotterStyle & style) = 0;

  /**
   * Set the style of a region and apply it to scene objects.
   */
    virtual bool applyStyle(const IPlotterStyle & style) = 0;

  /**
   * Set the title of a region.
   */
    virtual void setTitle(const std::string & title) = 0;

  /**
   * Set limit of an axis representation the region area.
   */
    virtual bool setXLimits(double min = 0, double max = 0) = 0;

    virtual bool setYLimits(double min = 0, double max = 0) = 0;

    virtual bool setZLimits(double min = 0, double max = 0) = 0;

  /**
   * To customize axis position,etc...
   * Change object position in the scence.
   */
    virtual IPlotterLayout & layout() = 0;

    virtual bool setLayout(const IPlotterLayout & layout) = 0;

  /**
   * Return an IInfo object describing the info area.
   */
    virtual IInfo & info() = 0;
}; // class
} // namespace AIDA
#endif /* ifndef AIDA_IPLOTTERREGION_H */
