import { createStore, combineReducers, applyMiddleware, compose } from 'redux';
import { hashHistory } from 'react-router'

import reducers from '../reducers'

const enhancer = compose(
	//for redux devtool in chrome console
	window.devToolsExtension ? window.devToolsExtension() : f => f
);

const rootReducer = combineReducers({
	...reducers
})

export default function configureStore(initialState) {
	const store = createStore(rootReducer, initialState, enhancer);
	return store;
}
