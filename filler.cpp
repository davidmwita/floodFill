/**
 * @file filler.cpp
 * Implementation of functions in the filler namespace.
 *
 */

/**
 * Performs a multi-point flood fill using breadth first search.
 *
 * @param config      FillerConfig struct to setup the fill
 * @return animation  object illustrating progression of flood fill algorithm
 */
animation filler::fillBFS(FillerConfig &config)
{
    animation animation = fill<Queue>(config);
    return animation;
}

/**
 * Performs a multi-point flood fill using depth first search.
 *
 * @param config      FillerConfig struct to setup the fill
 * @return animation  object illustrating progression of flood fill algorithm
 */
animation filler::fillDFS(FillerConfig &config)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill.
     */
     animation animation = fill<Stack>(config);
     return animation;
}

/**
 * Run a multi-point flood fill on an image
 *
 * @param  config     FillerConfig struct with data for flood fill of image
 * @return animation  object illustrating progression of flood fill algorithm
 */
template <template <class T> class OrderingStructure> animation filler::fill(FillerConfig &config)
{
  animation animation;
  int frameCount = 0;

  PNG img = config.img;
  unsigned int width = img.width();
  unsigned int height = img.height();

  animation.addFrame(img);

  vector<vector<bool>> processed(height , vector<bool> (width, false));

  float tolerance = config.tolerance;
  int frameFreq = config.frameFreq;

  int n = config.centers.size();

  for(int i = 0; i < n; i++) {
    OrderingStructure<struct point> os;

    colorPicker * picker = config.pickers[i];
    struct point center = point(config.centers[i].x, config.centers[i].y, config.centers[i]);
    HSLAPixel centerColor = *img.getPixel(center.x, center.y); //p.c.color;

    // DO?? cause always going to be centers. Should I change them?
    HSLAPixel pixel = picker->operator()(center);
    HSLAPixel * imgPixel = img.getPixel(center.x, center.y);
    imgPixel->h = pixel.h;
    imgPixel->s = pixel.s;
    imgPixel->l = pixel.l;

    processed[center.y][center.x] = true;
    os.add(center);

    frameCount++;
    if (frameCount % frameFreq == 0) animation.addFrame(img);


    while (!os.isEmpty()) {
      struct point point = os.remove();

      struct point pointL(point.x-1, point.y, point.c);
      struct point pointD(point.x, point.y+1, point.c);
      struct point pointR(point.x+1, point.y, point.c);
      struct point pointU(point.x, point.y-1, point.c);


      if (isValid(processed, width, height, pointL.x, pointL.y) && centerColor.dist(*img.getPixel(pointL.x, pointL.y)) <= tolerance) {
        HSLAPixel pixel = picker->operator()(pointL);
        HSLAPixel * imgPixel = img.getPixel(pointL.x, pointL.y);
        imgPixel->h = pixel.h;
        imgPixel->s = pixel.s;
        imgPixel->l = pixel.l;

        processed[pointL.y][pointL.x] = true;
        os.add(pointL);

        frameCount++;
        if (frameCount % frameFreq == 0) animation.addFrame(img);
      }

      if (isValid(processed, width, height, pointD.x, pointD.y) && centerColor.dist(*img.getPixel(pointD.x, pointD.y)) <= tolerance) {
        HSLAPixel pixel = picker->operator()(pointD);
        HSLAPixel * imgPixel = img.getPixel(pointD.x, pointD.y);
        imgPixel->h = pixel.h;
        imgPixel->s = pixel.s;
        imgPixel->l = pixel.l;

        processed[pointD.y][pointD.x] = true;
        os.add(pointD);

        frameCount++;
        if (frameCount % frameFreq == 0) animation.addFrame(img);
      }


      if (isValid(processed, width, height, pointR.x, pointR.y) && centerColor.dist(*img.getPixel(pointR.x, pointR.y)) <= tolerance) {
        HSLAPixel pixel = picker->operator()(pointR);
        HSLAPixel * imgPixel = img.getPixel(pointR.x, pointR.y);
        imgPixel->h = pixel.h;
        imgPixel->s = pixel.s;
        imgPixel->l = pixel.l;

        processed[pointR.y][pointR.x] = true;
        os.add(pointR);

        frameCount++;
        if (frameCount % frameFreq == 0) animation.addFrame(img);
      }


      if (isValid(processed, width, height, pointU.x, pointU.y) && centerColor.dist(*img.getPixel(pointU.x, pointU.y)) <= tolerance) {
        HSLAPixel pixel = picker->operator()(pointU);
        HSLAPixel * imgPixel = img.getPixel(pointU.x, pointU.y);
        imgPixel->h = pixel.h;
        imgPixel->s = pixel.s;
        imgPixel->l = pixel.l;

        processed[pointU.y][pointU.x] = true;
        os.add(pointU);

        frameCount++;
        if (frameCount % frameFreq == 0) animation.addFrame(img);
      }
    }

  }

  animation.addFrame(img);
  return animation;
}






/**
 * checks whether a point is within the dimension of the image and whether
 * it has or has not been processed.
 *
 * @param processed     Array of boolean values to check
 * @param x,y           The x and y positions to check
 * @return boolean
 **/
bool isValid(vector<vector<bool>> & processed, int width, int height, int x, int y) {
  if (x < 0 || x >= width || y < 0 || y >= height)  return false;
  return !processed[y][x];
}
