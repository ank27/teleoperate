import React from 'react';
import { Provider } from 'react-redux'
import ReactDOM from 'react-dom';
import Router from './router';
import configureStore from './store'

const store = configureStore()

ReactDOM.render(
	<Provider store={store} >
		<Router />
	</Provider>,
	document.getElementById('root')
);
