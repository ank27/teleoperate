var webpack = require('webpack');
var path = require('path');

module.exports ={
	debug: false,
	entry: [
		'./src/index.js'
	],

	output: {
		path: __dirname + '/builds',
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
