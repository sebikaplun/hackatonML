/* Copyright (c) 2012 Research In Motion Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "imageprocessor.hpp"

//! [0]
ImageProcessor::ImageProcessor(const QByteArray &imageData, QObject *parent)
    : QObject(parent)
    , m_data(imageData)
{
}
//! [0]

//! [1]
void ImageProcessor::start()
{
    QImage image;

    image.loadFromData(m_data);

    image = image.scaled(768, 500, Qt::KeepAspectRatioByExpanding);

    // Image processing goes here, example could be adding water mark to the downloaded image

    emit finished(image);
}
//! [1]
