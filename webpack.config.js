const path = require("path");
const webpack = require("webpack");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const CleanWebpackPlugin = require("clean-webpack-plugin");
const UglifyJSPlugin = require("uglifyjs-webpack-plugin");

const production = process.env.NODE_ENV === "production";
const productionPlugins = [
  new CleanWebpackPlugin(["lib", "dist"]),
  new UglifyJSPlugin({ sourceMap: true })
];
const devPlugins = [];

if (process.env.ANALYZE_WEBPACK === "true") {
  const {BundleAnalyzerPlugin} = require('webpack-bundle-analyzer');
  productionPlugins.push(new BundleAnalyzerPlugin())
  devPlugins.push(new BundleAnalyzerPlugin())
}

module.exports = {
  entry: "./src/main",
  output: {
    path: path.join(__dirname, "dist"),
    filename: "[name].js"
  },
  devtool: production ? "hidden-source-map" : "inline-source-map",
  module: {
    rules: [{ test: /\.(re|ml)$/, use: "bs-loader" }]
  },
  resolve: {
    extensions: [".re", ".ml", ".js"]
  },
  plugins: [
    ...(production ? productionPlugins : devPlugins),
    new HtmlWebpackPlugin({ template: "src/index.html" }),
    new webpack.DefinePlugin({
      "process.env": {
        NODE_ENV: JSON.stringify(process.env.NODE_ENV || "development")
      }
    })
  ]
};
