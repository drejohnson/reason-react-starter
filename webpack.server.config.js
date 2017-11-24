const fs = require('fs')
const path = require('path')
const nodeExternals = require('webpack-node-externals')
const webpack = require('webpack')

const isPROD = process.env.NODE_ENV === 'production'
const isDEV = !isPROD
const appDirectory = fs.realpathSync(process.cwd())
const resolveApp = relativePath => path.resolve(appDirectory, relativePath)

module.exports = {
  target: 'node',
  node: {
    __dirname: false
  },
  entry: resolveApp('lib/js/server/server.bs.js'),
  output: {
    path: resolveApp('build'),
    filename: 'server/index.js',
    libraryTarget: 'commonjs2'
  },
  resolve: {
    extensions: [
      '.re',
      '.ml',
      '.web.js',
      '.mjs',
      '.js',
      '.json',
      '.web.jsx',
      '.jsx'
    ]
  },
  plugins: isPROD
    ? [new webpack.HotModuleReplacementPlugin()]
    : [
      new webpack.DefinePlugin({
        APP_BUNDLE: JSON.stringify(
            isPROD
              ? require(resolveApp('build/asset-manifest.json'))['app.js']
              : 'static/js/app.js'
          ),
        VENDOR_BUNDLE: JSON.stringify(
            isPROD
              ? require(resolveApp('build/asset-manifest.json'))['vendors.js']
              : 'static/js/vendors.js'
          )
      })
    ],
  externals: [nodeExternals()]
}
