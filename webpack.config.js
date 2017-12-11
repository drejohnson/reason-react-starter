const fs = require('fs')
const path = require('path')
const HtmlWebpackPlugin = require('html-webpack-plugin')
const SWPrecacheWebpackPlugin = require('sw-precache-webpack-plugin')
const CleanWebpackPlugin = require('clean-webpack-plugin')
const CopyWebpackPlugin = require('copy-webpack-plugin')
const ManifestPlugin = require('webpack-manifest-plugin')
const UglifyJsPlugin = require('uglifyjs-webpack-plugin')
const ClosureCompilerPlugin = require('webpack-closure-compiler')
const rollupPluginNodeResolve = require('rollup-plugin-node-resolve')
const ShakePlugin = require('webpack-common-shake').Plugin
const webpack = require('webpack')

const HOST = process.env.HOST || 'localhost'
const PORT = process.env.PORT || 8080
const isPROD = process.env.NODE_ENV === 'production'
const appDirectory = fs.realpathSync(process.cwd())
const resolveApp = relativePath => path.resolve(appDirectory, relativePath)

module.exports = {
  name: 'client',
  devtool: isPROD ? false : 'cheap-module-source-map',
  entry: {
    app: isPROD ?
      resolveApp('src/index.bs.js') : [
        'react-hot-loader/patch',
        `webpack-hot-middleware/client?reload=true`,
        resolveApp('src/index.bs.js')
      ]
  },
  output: {
    path: resolveApp('build'),
    filename: `static/js/[name]${isPROD ? '.[chunkhash:8]' : ''}.js`,
    publicPath: '/'
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
  module: {
    rules: [{
        test: /\.js$/,
        loader: 'rollup-loader',
        options: {
          plugins: [rollupPluginNodeResolve({
            module: true
          })]
        },
        exclude: /node_modules/
      },
      {
        test: /\.(jpe?g|png|gif|ico|svg|webp)$/,
        exclude: /node_modules/,
        use: [{
          loader: 'url-loader',
          options: {
            limit: 10000,
            name: `static/images/[path][name]${isPROD ? '.[hash:8]' : ''}.[ext]`
          }
        }]
      }
    ]
  },
  plugins: [
    ...(isPROD ? [
      // Production Plugins
      new SWPrecacheWebpackPlugin({
        // By default, a cache-busting query parameter is appended to requests
        // used to populate the caches, to ensure the responses are fresh.
        // If a URL is already hashed by Webpack, then there is no concern
        // about it being stale, and the cache-busting can be skipped.
        dontCacheBustUrlsMatching: /\.\w{8}\./,
        filename: 'service-worker.js',
        logger(message) {
          if (message.indexOf('Total precache size is') === 0) {
            // This message occurs for every build and is a bit too noisy.
            return
          }
          if (message.indexOf('Skipping static resource') === 0) {
            // This message obscures real errors so we ignore it.
            // https://github.com/facebookincubator/create-react-app/issues/2612
            return
          }
          console.log(message)
        },
        minify: true,
        // For unknown URLs, fallback to the index page
        navigateFallback: '/',
        // Ignores URLs starting from /__ (useful for Firebase):
        // https://github.com/facebookincubator/create-react-app/issues/2237#issuecomment-302693219
        navigateFallbackWhitelist: [/^(?!\/__).*/],
        // Don't precache sourcemaps (they're large) and build asset manifest:
        staticFileGlobsIgnorePatterns: [/\.map$/, /asset-manifest\.json$/]
      }),
      new ClosureCompilerPlugin({
        compiler: {
          language_in: 'ECMASCRIPT6',
          language_out: 'ECMASCRIPT5'
        },
        concurrency: 3
      }),
      new UglifyJsPlugin({
        uglifyOptions: {
          ecma: 8,
          output: {
            comments: false,
            beautify: false,
          },
          compress: {
            comparisons: false
          },
          warnings: false
        }
      }),
      new ShakePlugin()
    ] : [
      // Development Plugins
      new webpack.NamedModulesPlugin(),
      new webpack.HotModuleReplacementPlugin()
    ]),
    // Common Plugins
    new ManifestPlugin({
      fileName: 'asset-manifest.json'
    }),
    new webpack.optimize.CommonsChunkPlugin({
      name: 'vendors',
      // async: true,
      // children: true,
      // minChunks: 2
      minChunks: module => /node_modules/.test(module.resource)
    }),
    new webpack.optimize.ModuleConcatenationPlugin(),
    new CleanWebpackPlugin(resolveApp('build')),
    new CopyWebpackPlugin([{
      from: resolveApp('public'),
      ignore: ['*.html']
    }]),
    new webpack.EnvironmentPlugin({
      NODE_ENV: isPROD ? 'production' : 'development',
      PUBLIC_URL: JSON.stringify(path.resolve(__dirname, 'build'))
    })
  ],
  performance: {
    hints: false
  },
  node: {
    dgram: 'empty',
    fs: 'empty',
    net: 'empty',
    tls: 'empty',
    child_process: 'empty'
  },
  bail: isPROD
}