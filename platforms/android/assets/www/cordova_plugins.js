cordova.define('cordova/plugin_list', function(require, exports, module) {
module.exports = [
    {
        "file": "plugins/cordova-plugin-sms/www/SMS.js",
        "id": "cordova-plugin-sms.SMS",
        "clobbers": [
            "window.SMS"
        ]
    }
];
module.exports.metadata = 
// TOP OF METADATA
{
    "cordova-plugin-whitelist": "1.2.2",
    "cordova-plugin-sms": "1.0.5"
};
// BOTTOM OF METADATA
});