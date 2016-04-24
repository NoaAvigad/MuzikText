# cordova-plugin-muzik

This plugin defines a global `muzik` object, which provides an API for accessing Muzik Convertible Headphones. Although the object is in the global scope, features provided by this plugin are not available until after the deviceready event.

```
document.addEventListener("deviceready", onDeviceReady, false);
function onDeviceReady() {
    console.log("navigator.geolocation works well");
}
```

## Documentation

Full documentation of the API is viewable on the [wiki](https://github.com/MuzikLLC/cordova-plugin-muzik/wiki).

## Supported Platforms

* Android
* iOS
