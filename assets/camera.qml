
import bb.cascades 1.0
import bb.cascades.multimedia 1.0
import bb.multimedia 1.0

Page {
    id: page
    Container {
        layout: DockLayout {

        }
        ImageView {
            imageSource: "asset:///header.png"
            verticalAlignment: VerticalAlignment.Top
        }
        Camera {
            property bool photoBeingTaken
            id: qrcodeCamera
            //            objectName: "qrcodeCamera"
            onTouch: {
                if (event.isDown()) {
                    // Take photo
                    capturePhoto();
                }
            }
            onCameraOpened: {
                getSettings(qrcodeCameraSettings)
                qrcodeCameraSettings.focusMode = CameraFocusMode.ContinuousAuto
                qrcodeCameraSettings.shootingMode = CameraShootingMode.Stabilization
                applySettings(qrcodeCameraSettings)

                qrcodeCamera.startViewfinder()
            }
            onShutterFired: {
                // A cool trick here to play a sound. There are legal requirements in many countries to have a shutter-sound when
                // taking pictures. So we need this shutter sound if you are planning to submit you're app to app world.
                // So we play the shutter-fire sound when the onShutterFired event occurs.
                cameraSound.play();
            }

            onCameraOpenFailed: {
                console.debug("Camera open FAILED: " + error);
            }
            onViewfinderStarted: {
                console.debug("Viewfinder started");
                photoBeingTaken = false;
            }
            onViewfinderStartFailed: {
                console.debug("Viewfinder start FAILED: " + error);
            }
            onPhotoCaptureFailed: {
                console.debug("Photo caputre FAILED: " + error);
                photoBeingTaken = false;
            }
            onPhotoSaveFailed: {
                console.debug("Photo save FAILED: " + error);
                photoBeingTaken = false;
            }
            onPhotoSaved: {
                console.debug("Photo URI: " + fileName);
                photoBeingTaken = false;
                loadingContainer.visible = true;
                appContext.pushImage(fileName);
            }
            attachedObjects: [
                CameraSettings {
                    id: qrcodeCameraSettings
                }
            ]
        }
        Container {
            id: loadingContainer
            visible: false
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
                text: "Reconociendo imágen"
                textStyle.fontSize: FontSize.XXLarge
            }
        }

        attachedObjects: [
            // Required to play the shutter sound.
            SystemSound {
                id: cameraSound
                sound: SystemSound.CameraShutterEvent
            },

            CameraSettings {
                id: settings
            }
        ]

    }
    onCreationCompleted: {
        // Check to see if any cameras are currently accessible.
        if (qrcodeCamera.allCamerasAccessible) {
            // Open the rear camera.
            qrcodeCamera.open(CameraUnit.Rear);
        }
    }
    onActionMenuVisualStateChanged: {
        
    }
}
