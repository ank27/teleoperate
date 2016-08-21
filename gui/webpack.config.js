var webpack = require('webpack');
var path = require('path');

module.exports ={
	debug: false,
	entry: [
		'webpack-dev-server/client?http://0.0.0.0:3000', // WebpackDevServer host and port
		'webpack/hot/only-dev-server', // "only" prevents reload on syntax errors
		'./src/index.js'
	],

	output: {
		path: 'builds/',
		filename: 'bundle.js',
		publicPath: "/builds/",        
		pathinfo: true,
	},
	resolve: {
		// Absolute path that contains modules
		root: __dirname,
		// Directory names to be searched for modules
		modulesDirectories: ['node_modules'],

	},
	resolveLoader: {
		modulesDirectories:['node_modules']
	},
	module: {
		loaders: [
			{
				test: /\.js/,
				loaders: ['react-hot','babel'],
				include: [
					path.resolve('./src/')
				],
			},
		]
	},
	devServer: {
		historyApiFallback: true,
	},
}
