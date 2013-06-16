
import bb.cascades 1.0

NavigationPane {
    id: nav
    property string query

    Page {
        Container {
            ImageView {
                imageSource: "asset:///header.png"
            }
            Container {
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }
                TextField {
                    id: queryField
                    inputMode: TextFieldInputMode.Url
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 3
                    }
                }
                Button {
                    text: "Buscar"
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1
                    }
                    onClicked: {
                        query = queryField.text;
                        console.log(query);
                        query = query.replace(" ", "+");
                        console.log(query);
                        var page = finderDefinition.createObject();
                        page.query2 = queryField.text;
                        page.queryOriginal = queryField.text;
                        nav.push(page);
                    }
                    attachedObjects: [
                        ComponentDefinition {
                            id: finderDefinition
                            source: "imageFinder.qml"
                        }
                    ]
                }

            }

            Button {
                text: "Cargar imágenes"
                onClicked: {
                    var page = secondPageDefinition.createObject();
                    nav.push(page);
                }
                attachedObjects: [
                    ComponentDefinition {
                        id: secondPageDefinition
                        source: "camera.qml"
                    }
                ]

            }
        }
    }
    onPopTransitionEnded: {
        page.destroy();
    }
}