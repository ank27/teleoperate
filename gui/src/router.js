import React from 'react';
import { Router, Route, browserHistory, IndexRoute } from 'react-router'
import App from './components/App' 

export default () => {
	return (
		<Router history= {browserHistory}>
			<Route path="/" component={App} >
				<IndexRoute getComponent = { (location, callback) => {
					System.import('./components/Home').then(loadRoute(callback)).catch(errorLoading); }} />
			</Route>
		</Router>
	)
}

function errorLoading(err) {
	console.error('Dynamic page loading failed', err);
}


function loadRoute(cb) {
	return (module) => cb(null, module.default);
}
