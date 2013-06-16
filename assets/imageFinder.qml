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

import bb.cascades 1.0
import bb.data 1.0

Page {
    property string query2
    property string queryOriginal
    Container {
        layout: DockLayout {
        }

        // The background image
        ImageView {
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill

            imageSource: "asset:///images/background.png"
        }

        //! [1]
        // The ListView that shows the progress of loading and result images
        ListView {
            id: listView

            layout: GridListLayout {
            }

            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill

            dataModel: appContext.model
            //! [1]

            //! [2]
            listItemComponents: ListItemComponent {
                type: ""
                Container {
                    preferredHeight: 500
                    preferredWidth: 768

                    layout: DockLayout {
                    }

                    // The ActivityIndicator that is only active and visible while the image is loading
                    ActivityIndicator {
                        horizontalAlignment: HorizontalAlignment.Center
                        verticalAlignment: VerticalAlignment.Center
                        preferredHeight: 300

                        visible: ListItemData.loading
                        running: ListItemData.loading
                    }

                    // The ImageView that shows the loaded image after loading has finished without error
                    ImageView {
                        horizontalAlignment: HorizontalAlignment.Fill
                        verticalAlignment: VerticalAlignment.Fill

                        image: ListItemData.image
                        visible: ! ListItemData.loading && ListItemData.label == ""
                        onImageChanged: {
                        }
                    }
                    ImageView {
                        verticalAlignment: VerticalAlignment.Top
                        horizontalAlignment: HorizontalAlignment.Center
                        imageSource: "asset:///" + ListItemData.seller + ".png"
                    }
                    Container {
                        preferredHeight: 55
                        preferredWidth: 500
                        background: Color.Black
                        verticalAlignment: VerticalAlignment.Bottom
                        Label {
                            textStyle.color: Color.White
                            text: "$" + ListItemData.price
                            horizontalAlignment: HorizontalAlignment.Center
                            onTextChanged: {
                                console.log(ListItemData.seller)
                            }
                        }

                    }

                    // The Label that shows a possible error message after loading has finished
                    Label {
                        horizontalAlignment: HorizontalAlignment.Center
                        verticalAlignment: VerticalAlignment.Center
                        preferredWidth: 500

                        visible: ! ListItemData.loading && ! ListItemData.label == ""
                        text: ListItemData.label
                        multiline: true
                    }
                    contextActions: [
                        ActionSet {
                            InvokeActionItem {
                                id: actionId
                                title: "Compartir"
                                query {
                                    invokeActionId: "bb.action.SHARE"
                                    mimeType: "text/plain"
                                    data: "Compartiendo esto"
                                    onQueryChanged: {
                                        actionId.query.updateQuery()
                                    }
                                }
                            }
                        }
                    ]
                }

            }
            //! [2]
        }
        Container {
            id: loadingContainer
            background: Color.Black
            preferredWidth: 1000
            layout: StackLayout {

            }
            verticalAlignment: VerticalAlignment.Center
            ActivityIndicator {
                horizontalAlignment: HorizontalAlignment.Center
                running: true
                preferredWidth: 800

            }
            Label {
                textStyle.color: Color.White
                horizontalAlignment: HorizontalAlignment.Center
                text: "Buscando '" + queryOriginal + "' en Mercado Libre"
                textStyle.fontSize: FontSize.Small
            }
        }
    }
    onCreationCompleted: {
        //_app.addImage("http://img2.mlstatic.com/s_MLA_v_I_f_3311268329_102012.jpg");
        //_app.loadImages();

    }
    onQuery2Changed: {
        query2 = query2.replace(" ", "-");
        dataSource.source = "http://jailbreaker.com.ar/hackml/search.php?q=" + query2;
        console.log(dataSource.source);
        dataSource.load();
    }
    attachedObjects: [
        GroupDataModel {
            id: dataModel

            // Sort the data in the data model by the "pubDate" field, in
            // descending order, without any automatic grouping
            sortingKeys: [ "pubDate" ]
            sortedAscending: false
            grouping: ItemGrouping.None
        },
        DataSource {
            id: dataSource
            source: ""
            // Load the XML data from a remote data source, specifying that the
            // "item" data items should be loaded
            type: DataSourceType.Json
            //query: ".results"
            onDataLoaded: {
                // After the data is loaded, clear any existing items in the data
                // model and populate it with the new data
                //dataModel.clear();
                //dataModel.insertList(data.results)
                //console.log(dataSource.source);
                loadingContainer.visible = false;
                for (var i = 0; i < data.results.length; i ++) {
                    //appContext.addImage(data.results[]});

                    console.log(data.results[i].reputa);

                    appContext.addImage(data.results[i].thumbnail, data.results[i].price, data.results[i].reputa);
                    //_app.loadImages();
                    //appContext.loadImages();
                }
                appContext.loadImages();
            }
        }
    ]

}
