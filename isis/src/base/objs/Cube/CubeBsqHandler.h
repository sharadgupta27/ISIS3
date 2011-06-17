/**
 * @file
 * $Revision: 1.4 $
 * $Date: 2008/09/03 16:21:02 $
 *
 *   Unless noted otherwise, the portions of Isis written by the USGS are
 *   public domain. See individual third-party library and package descriptions
 *   for intellectual property information, user agreements, and related
 *   information.
 *
 *   Although Isis has been used by the USGS, no warranty, expressed or
 *   implied, is made by the USGS as to the accuracy and functioning of such
 *   software and related material nor shall the fact of distribution
 *   constitute any such warranty, and no responsibility is assumed by the
 *   USGS in connection therewith.
 *
 *   For additional information, launch
 *   $ISISROOT/doc//documents/Disclaimers/Disclaimers.html
 *   in a browser or see the Privacy &amp; Disclaimers page on the Isis website,
 *   http://isis.astrogeology.usgs.gov, and the USGS privacy and disclaimers on
 *   http://www.usgs.gov/privacy.html.
 */
#ifndef CubeBsqHandler_h
#define CubeBsqHandler_h

#include "CubeIoHandler.h"

namespace Isis {
  /**
   * @internal
   *   @todo CubeBsqHandler doesn't have any documentation.
   *
   * @brief IO Handler for Isis Cubes using the BSQ format.
   *
   * This class is used to open, create, read, and write data from Isis cube
   * files.
   *
   * @ingroup LowLevelCubeIO
   *
   * @author 2003-02-14 Jeff Anderson
   *
   * @internal
   *   @history 2007-09-14 Stuart Sides - Fixed bug where pixels
   *            from a buffer outside the ns/nl were being
   *            transfered to the right most and bottom most tiles
   *   @history 2007-10-11 Stuart Sides - Fixed bug introduced with
   *            previous bug fix.
   *   @history 2008-09-03 Steven Lambright - Fixed MSB/LSB problem with
   *            the Move(...) method
   */
  class CubeBsqHandler : public CubeIoHandler {
    public:
      CubeBsqHandler(QFile * dataFile, QList<int> *virtualBandList,
          const Pvl &label, bool alreadyOnDisk);
      ~CubeBsqHandler();

      void updateLabels(Pvl &label);

    protected:
      virtual void readRaw(RawCubeChunk &chunkToFill) const;
      virtual void writeRaw(const RawCubeChunk &chunkToWrite) const;

    private:
      BigInt getChunkStartByte(const RawCubeChunk &chunk) const;
  };
}

#endif
