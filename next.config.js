const withTM = require("next-transpile-modules")([
  "bs-platform",
  "@ahrefs/bs-emotion",
  "@minima.app/re-css",
  "reason-promise",
  "reason-apollo-client"
]);



module.exports = withTM({
  pageExtensions: ["jsx", "js", "bs.js"],
  webpack: function (config) {
    config.module.rules.push({
      test: /\.md$/,
      use: "raw-loader",
    });
    return config;
  },
});
