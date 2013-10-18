/**
 * @name MFT.AvoidAreasView
 * 
 * @desc Settings Settings Navigation AvoidAreas module visual representation
 * 
 * @category	View
 * @filesource	app/view/settings/innersettings/navigation/AvoidAreasView.js
 * @version		2.0
 *
 * @author		Maksym Gerashchenko
 */

MFT.SettingsSettingsNavigationAreasView = Em.ContainerView.create(MFT.LoadableView,{

	elementId:		'settings_settings_navigation_avoidAreas_view',
    classNames: 'settings-list-block',
			
	childViews: [
		'backButton',
		'topTitile',
		'addButton'
	],
	
	backButton: MFT.Button.extend({
		elementId:		   'settings_settings_navigation_avoidAreas_backButton_button',
		classNames:		  ['backButton','button'],		
		action:			  'back',
		target:			  'MFT.States',	
		icon:				'images/media/ico_back.png'
	}),
	
	topTitile: MFT.Label.extend({
		elementId:		   'settings_settings_navigation_avoidAreas_headTtitle_label',
		classNames:		  ['block-header-title'],
		contentBinding:	  'MFT.locale.label.view_settings_settings_navigation_avoidAreas_title'
	}),		
	
	addButton: MFT.Button.extend({
		elementId:		   'settings_settings_navigation_avoidAreas_backButton_addButton',
		goToState:		   'add',			 
		classNames:		  ['button'],		
		action:			  'onChildState',
		target:			  'MFT.settingsController',	
		templateName:		'arrow',
		textBinding:		 'MFT.locale.label.view_settings_settings_navigation_avoidAreas_add',
		disabled:	        true
	})

});